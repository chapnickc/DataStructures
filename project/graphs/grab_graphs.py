import overpass

api = overpass.API()
response = api.Get('node["name"="Salt Lake City"]',responseformat='json')
response.keys()
response['generator']
response['osm3s']
response['elements']



map_query = overpass.MapQuery(50.746,7.154,50.748,7.157)
response = api.Get(map_query)

response.keys()
response['type']
response['features'][:10]

#---------------------------------------------------------
import overpy


api = overpy.Overpass()
result = api.query("[out:json]; node(50.745,7.17,50.75,7.18); out;")
len(result.nodes)
len(result.ways)
len(result.relations)



# fetch all ways and nodes
result = api.query("""
    way(50.746,7.154,50.748,7.157) ["highway"];
    (._;>;);
    out body;
    """)


plt.clf()
for way in result.ways:
    print("Name: {}\t\tHighway: {}".format(way.tags.get("name", "n/a"), way.tags.get("highway", "n/a")))
    latlong = []
    for node in way.nodes:
        latlong.append((float(node.lat), float(node.lon)))
    plt.plot([c[0] for c in latlong], [c[1] for c in latlong], 'k.')
    plt.plot([c[0] for c in latlong], [c[1] for c in latlong], '-', label=way.tags.get("name", "n/a"))
plt.legend()





import overpy.helper

# 3600062594 is the OSM id of Chemnitz and is the bounding box for the request
street = overpy.helper.get_street(
    "Straße der Nationen",
    "3600062594"
)


# this finds an intersection between Straße der Nationen and Carolastraße in Chemnitz
intersection = overpy.helper.get_intersection(
    "Straße der Nationen",
    "Carolastraße",
    "3600062594"
)

m = [*map(lambda node: [float(node.lat), float(node.lon)], intersection)]

plt.plot([c[0] for c in m], [c[1] for c in m],'k.')
plt.show()


intersection
