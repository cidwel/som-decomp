.setcpu "65816"
.segment "CODE"
.org $64FC
map_control_0d64fc:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
