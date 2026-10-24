.setcpu "65816"
.segment "CODE"
.org $EE0A
map_control_0fee0a:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
