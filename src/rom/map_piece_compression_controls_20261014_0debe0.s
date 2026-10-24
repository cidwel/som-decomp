.setcpu "65816"
.segment "CODE"
.org $EBE0
map_control_0debe0:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
