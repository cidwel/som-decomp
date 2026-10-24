.setcpu "65816"
.segment "CODE"
.org $402A
map_control_0c402a:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
