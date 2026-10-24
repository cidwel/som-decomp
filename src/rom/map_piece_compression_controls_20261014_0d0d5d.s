.setcpu "65816"
.segment "CODE"
.org $0D5D
map_control_0d0d5d:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
