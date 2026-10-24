.setcpu "65816"
.segment "CODE"
.org $A095
map_control_0da095:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
