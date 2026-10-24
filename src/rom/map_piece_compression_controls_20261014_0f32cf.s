.setcpu "65816"
.segment "CODE"
.org $32CF
map_control_0f32cf:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
