.setcpu "65816"
.segment "CODE"
.org $2FAB
map_control_0e2fab:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
