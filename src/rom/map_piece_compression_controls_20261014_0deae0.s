.setcpu "65816"
.segment "CODE"
.org $EAE0
map_control_0deae0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
