.setcpu "65816"
.segment "CODE"
.org $B04C
map_control_0eb04c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
