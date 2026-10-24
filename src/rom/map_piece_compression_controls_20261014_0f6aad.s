.setcpu "65816"
.segment "CODE"
.org $6AAD
map_control_0f6aad:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
