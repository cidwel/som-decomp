.setcpu "65816"
.segment "CODE"
.org $5C8A
map_control_0f5c8a:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
