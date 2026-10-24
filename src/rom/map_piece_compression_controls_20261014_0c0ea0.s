.setcpu "65816"
.segment "CODE"
.org $0EA0
map_control_0c0ea0:
    .byte $EE ; backreference distance high bits
    .byte $95 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
