.setcpu "65816"
.segment "CODE"
.org $5F89
map_control_0f5f89:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6C ; row-distance/count
