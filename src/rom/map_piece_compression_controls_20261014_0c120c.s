.setcpu "65816"
.segment "CODE"
.org $120C
map_control_0c120c:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
