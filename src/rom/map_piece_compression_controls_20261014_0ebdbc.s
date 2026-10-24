.setcpu "65816"
.segment "CODE"
.org $BDBC
map_control_0ebdbc:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
