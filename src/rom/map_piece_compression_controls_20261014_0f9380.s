.setcpu "65816"
.segment "CODE"
.org $9380
map_control_0f9380:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
