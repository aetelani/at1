sc:
	(cd statecharts/; scxmlcc flow.scxml)

run:
	 qbs && ./default/install-root/bin/at1
