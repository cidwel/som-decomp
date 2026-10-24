.setcpu "65816"
.segment "CODE"
.org $89A4
map_control_0d89a4:
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
