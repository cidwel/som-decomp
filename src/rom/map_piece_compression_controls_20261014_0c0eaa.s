.setcpu "65816"
.segment "CODE"
.org $0EAA
map_control_0c0eaa:
    .byte $EE ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
