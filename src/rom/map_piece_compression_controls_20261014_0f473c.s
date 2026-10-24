.setcpu "65816"
.segment "CODE"
.org $473C
map_control_0f473c:
    .byte $E0 ; previous-row copy escape
    .byte $EC ; row-distance/count
