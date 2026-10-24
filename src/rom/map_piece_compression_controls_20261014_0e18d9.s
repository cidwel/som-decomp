.setcpu "65816"
.segment "CODE"
.org $18D9
map_control_0e18d9:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
