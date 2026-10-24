.setcpu "65816"
.segment "CODE"
.org $613C
map_control_0c613c:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
