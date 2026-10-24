.setcpu "65816"
.segment "CODE"
.org $AE20
map_control_0dae20:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
