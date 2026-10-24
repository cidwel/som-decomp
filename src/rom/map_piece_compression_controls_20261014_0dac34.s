.setcpu "65816"
.segment "CODE"
.org $AC34
map_control_0dac34:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $A8 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
