.setcpu "65816"
.segment "CODE"
.org $DC27
map_control_0ddc27:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
