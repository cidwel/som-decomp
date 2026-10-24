.setcpu "65816"
.segment "CODE"
.org $267B
map_control_0f267b:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
