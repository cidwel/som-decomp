.setcpu "65816"
.segment "CODE"
.org $FA0B
map_control_0efa0b:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
