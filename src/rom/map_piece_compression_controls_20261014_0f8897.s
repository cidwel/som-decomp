.setcpu "65816"
.segment "CODE"
.org $8897
map_control_0f8897:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
