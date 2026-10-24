.setcpu "65816"
.segment "CODE"
.org $4F14
map_control_0f4f14:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
