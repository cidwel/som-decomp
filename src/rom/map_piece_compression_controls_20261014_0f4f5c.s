.setcpu "65816"
.segment "CODE"
.org $4F5C
map_control_0f4f5c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
