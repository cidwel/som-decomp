.setcpu "65816"
.segment "CODE"
.org $0F7B
map_control_0e0f7b:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
