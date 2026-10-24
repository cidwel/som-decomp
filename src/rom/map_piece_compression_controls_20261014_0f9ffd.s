.setcpu "65816"
.segment "CODE"
.org $9FFD
map_control_0f9ffd:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
