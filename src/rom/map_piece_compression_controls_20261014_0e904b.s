.setcpu "65816"
.segment "CODE"
.org $904B
map_control_0e904b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
