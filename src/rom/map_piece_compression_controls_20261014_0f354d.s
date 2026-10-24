.setcpu "65816"
.segment "CODE"
.org $354D
map_control_0f354d:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $6C ; row-distance/count
