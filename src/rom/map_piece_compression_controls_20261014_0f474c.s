.setcpu "65816"
.segment "CODE"
.org $474C
map_control_0f474c:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
