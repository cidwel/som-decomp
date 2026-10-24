.setcpu "65816"
.segment "CODE"
.org $904B
map_control_0c904b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
