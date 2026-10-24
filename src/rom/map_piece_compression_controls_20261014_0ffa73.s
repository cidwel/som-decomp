.setcpu "65816"
.segment "CODE"
.org $FA73
map_control_0ffa73:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
