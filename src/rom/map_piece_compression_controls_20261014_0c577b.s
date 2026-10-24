.setcpu "65816"
.segment "CODE"
.org $577B
map_control_0c577b:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
