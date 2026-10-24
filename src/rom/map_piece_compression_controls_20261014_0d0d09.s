.setcpu "65816"
.segment "CODE"
.org $0D09
map_control_0d0d09:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C4 ; row-distance/count
