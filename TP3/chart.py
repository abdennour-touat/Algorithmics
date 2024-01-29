import pandas as pd
import plotly.express as px

df = pd.read_csv('qst5.csv')

fig = px.line(df, x = 'taille', y = ['tempsrec','tempsiter'], title='resultat qst 3)')
fig.show()
