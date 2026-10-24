.setcpu "65816"
.segment "CODE"
.org $7F6C
map_control_0f7f6c:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
