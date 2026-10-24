.setcpu "65816"
.segment "CODE"
.org $53CF
map_control_0c53cf:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
