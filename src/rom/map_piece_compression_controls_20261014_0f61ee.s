.setcpu "65816"
.segment "CODE"
.org $61EE
map_control_0f61ee:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
