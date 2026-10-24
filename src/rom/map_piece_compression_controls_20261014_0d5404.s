.setcpu "65816"
.segment "CODE"
.org $5404
map_control_0d5404:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
