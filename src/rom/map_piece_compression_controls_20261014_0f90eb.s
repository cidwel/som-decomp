.setcpu "65816"
.segment "CODE"
.org $90EB
map_control_0f90eb:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
