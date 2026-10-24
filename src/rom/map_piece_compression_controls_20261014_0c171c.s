.setcpu "65816"
.segment "CODE"
.org $171C
map_control_0c171c:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
