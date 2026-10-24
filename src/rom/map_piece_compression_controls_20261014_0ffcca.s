.setcpu "65816"
.segment "CODE"
.org $FCCA
map_control_0ffcca:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
