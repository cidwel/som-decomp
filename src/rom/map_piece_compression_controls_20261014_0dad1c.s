.setcpu "65816"
.segment "CODE"
.org $AD1C
map_control_0dad1c:
    .byte $E0 ; previous-row copy escape
    .byte $DE ; row-distance/count
