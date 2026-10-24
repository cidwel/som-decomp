.setcpu "65816"
.segment "CODE"
.org $2909
map_control_0c2909:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
