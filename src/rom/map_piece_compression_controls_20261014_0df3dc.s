.setcpu "65816"
.segment "CODE"
.org $F3DC
map_control_0df3dc:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
