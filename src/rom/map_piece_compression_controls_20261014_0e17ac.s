.setcpu "65816"
.segment "CODE"
.org $17AC
map_control_0e17ac:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
