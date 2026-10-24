.setcpu "65816"
.segment "CODE"
.org $0827
map_control_0d0827:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
