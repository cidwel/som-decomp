.setcpu "65816"
.segment "CODE"
.org $D34B
map_control_0ed34b:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
