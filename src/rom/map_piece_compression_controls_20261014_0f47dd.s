.setcpu "65816"
.segment "CODE"
.org $47DD
map_control_0f47dd:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
