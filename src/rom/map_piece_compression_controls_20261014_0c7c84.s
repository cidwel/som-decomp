.setcpu "65816"
.segment "CODE"
.org $7C84
map_control_0c7c84:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
