.setcpu "65816"
.segment "CODE"
.org $1A54
; Unread thirteenth pitch constant: floor(4096 * 2^(1/12)).
; All thirteen contiguous words match the same semitone formula; native DIV12 reads the first twelve.
.word 4339
